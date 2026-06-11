#include <bits/stdc++.h>
using namespace std;


int64_t combi(vector<int64_t> data){
    int64_t answer = 0;

    answer = data.at(0)*data.at(1)*data.at(2) +
                data.at(0)*data.at(1)*data.at(3) +
                data.at(0)*data.at(1)*data.at(4) +
                data.at(0)*data.at(2)*data.at(3) +
                data.at(0)*data.at(2)*data.at(4) +
                data.at(0)*data.at(3)*data.at(4) +
                data.at(1)*data.at(2)*data.at(3) +
                data.at(1)*data.at(2)*data.at(4) +
                data.at(1)*data.at(3)*data.at(4) +
                data.at(2)*data.at(3)*data.at(4);

    return answer;
}


int main(){

    int n;
    cin >> n;

    vector<int64_t> data(5, 0);

    for (int i = 0; i<n; i++){
        string a;
        cin >> a;

        if (a.at(0) == 'M'){
            data.at(0)++;
        }else if (a.at(0) == 'A'){
            data.at(1)++;
        }else if (a.at(0) == 'R'){
            data.at(2)++;
        }else if (a.at(0) == 'C'){
            data.at(3)++;
        }else if (a.at(0) == 'H'){
            data.at(4)++;
        }
    }

    int64_t ans = combi(data);

    cout << ans << endl;

}