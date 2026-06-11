#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>

using namespace std;

bool dp[8001][16001];

bool can_reach(vector <int> moves, int pos){
    int total_moves = accumulate(moves.begin(), moves.end(), 0);
    //cout << total_moves << " " << pos << endl;
    if(pos > total_moves || (- total_moves) > pos){
        return false;
    }

    for(int i  = 0; i < moves.size() + 1; i++){
        for(int j = 0; j < 2 * total_moves + 1; j++){
            dp[i][j] = false;
        }
    }

    dp[0][total_moves] = true;
    for(int i = 1; i <= moves.size(); i++){
        //cout << "moves " << moves[i] << endl;
        for(int j = 0; j < 2 * total_moves + 1; j++){
            if(j + moves[i - 1] < 2 * total_moves + 1){
                dp[i][j] |= dp[i - 1][j + moves[i - 1]];
            }
            if(j - moves[i - 1] >= 0){
                dp[i][j] |= dp[i - 1][j - moves[i - 1]];
            }
        }
    }

    /*
    for(int i = 0; i <= moves.size(); i++){
        for(int j = 0; j < 2 * total_moves + 1; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    return dp[moves.size()][pos + total_moves];
}

int main(){
    string S;
    int x;
    int y;
    cin >> S;
    cin >> x >> y;

    vector <int> horizontal_moves;
    vector <int> vertical_moves;

    bool horizontal = true;
    int cur_move_size = 0;
    for(int i = 0; i < S.size(); i++){
        //cout << horizontal << endl;
        if(S[i] == 'F'){
            cur_move_size ++;
        }
        if(S[i] == 'T' || i == S.size() - 1){
            if(horizontal){
                horizontal_moves.push_back(cur_move_size);
            } else {
                vertical_moves.push_back(cur_move_size);
            }
            horizontal = !horizontal;
            cur_move_size = 0;
        }
    }
    
    /*
    for(int i = 0; i < horizontal_moves.size(); i++){
        cout << horizontal_moves[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < vertical_moves.size(); i++){
        cout << vertical_moves[i] << " ";
    }
    cout << endl;
    */

    x -= horizontal_moves[0];
    horizontal_moves.erase(horizontal_moves.begin(), horizontal_moves.begin() + 1);

    /* 
    for(int i = 0; i < horizontal_moves.size(); i++){
        cout << horizontal_moves[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < vertical_moves.size(); i++){
        cout << vertical_moves[i] << " ";
    }
    cout << endl;
    */

    if(can_reach(horizontal_moves, x) && can_reach(vertical_moves, y)){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
