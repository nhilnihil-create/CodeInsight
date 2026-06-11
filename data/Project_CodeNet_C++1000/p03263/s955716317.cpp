#include <iostream>
//#include <set>
//#include <map>
//#include <iomanip>
//#include <algorithm>
//#include <numeric>
//#include <queue>
//#include <stack>
//#include <math.h>
#include <vector>
//#include <string>
//#include <list>
//#include <deque>
//#include <unordered_map>
//typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 200100
//#define NIL -1

int main() {
    int h;
    int w;
    int num_move=0;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    vector<pair<int, int>> xy_start;
    vector<pair<int, int>> xy_end;

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> a[i][j];
        }
    }

    for(int i=0; i<h; i++){
        if(i%2==0){
            for(int j=0; j<w; j++){
                if(a[i][j]%2!=0){
                    if(j<w-1){
                        a[i][j]--;
                        a[i][j+1]++;
                        xy_start.push_back(make_pair(i, j));
                        xy_end.push_back(make_pair(i, j+1));
                        num_move++;
                    }else if(i<h-1){
                        a[i][j]--;
                        a[i+1][j]++;
                        xy_start.push_back(make_pair(i, j));
                        xy_end.push_back(make_pair(i+1, j));
                        num_move++;
                    }
                }
            }
        }else{
            for(int j=w-1; j>=0; j--){
                if(a[i][j]%2!=0){
                    if(j>0){
                        a[i][j]--;
                        a[i][j-1]++;
                        xy_start.push_back(make_pair(i, j));
                        xy_end.push_back(make_pair(i, j-1));
                        num_move++;
                    }else if(i<h-1){
                        a[i][j]--;
                        a[i+1][j]++;
                        xy_start.push_back(make_pair(i, j));
                        xy_end.push_back(make_pair(i+1, j));
                        num_move++;
                    }
                }
            }
        }
    }

    cout << num_move << endl;
    for(int i=0; i<num_move; i++){
        cout << xy_start[i].first+1 << " " << xy_start[i].second+1 << " " << xy_end[i].first+1 << " " << xy_end[i].second+1 << endl;
    }

    return 0;
}