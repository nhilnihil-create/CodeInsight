#include <bits/stdc++.h>
using namespace std;
int main(){
    int s,i = 1;
    cin >> s;
    vector<int> data(1000000);
    data.at(0) = s;
    bool flag_m = 0;
    while(1){
        if(data.at(i-1) % 2 == 0){//偶数だったら

            data.at(i) = data.at(i-1) / 2;

            for (int j = 0; j < i; j++){
                if(data.at(i) == data.at(j)) 
                    flag_m = 1;
            }

        }else{//奇数だったら

            data.at(i) = data.at(i-1) * 3 + 1;

            for (int j = 0; j < i; j++){
                if(data.at(i) == data.at(j)) 
                    flag_m = 1;
            }

        }
        i++;
        if(flag_m)break;
    }
    cout << i << endl;
}