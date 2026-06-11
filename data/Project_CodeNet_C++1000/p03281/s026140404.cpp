#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

int main() {

    int N;

    vector<int> n_vec;

    int cnt = 0;

    cin >> N ;

    for (int i = 1; i <= N; i++){

        if(i % 2 == 1){
            n_vec.push_back(i);
        }
    }

    
    for (int i = 0; i < n_vec.size(); i++){
        int t = n_vec.at(i);
        int tmp = 0;
        for (int j = 1; j <= N; j++){
            if (t % j == 0){
                tmp++;
            }
        }
        if (tmp == 8){
            cnt++;
        }

    }

    cout << cnt << endl;




}