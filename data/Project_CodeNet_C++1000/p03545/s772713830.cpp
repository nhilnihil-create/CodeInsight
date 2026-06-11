#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string input;
    cin >> input;
    vector<int> num(4);
    for(int i = 0; i < 4; i++) num[i] = input[i]-'0';

    string ans = "";
    for(int i = 0; i <= 1; i++){
        for(int j = 0; j <= 1; j++){
            for(int k = 0; k <= 1; k++){
                int ansnum = num[0];
                if(i == 1) ansnum += num[1];
                else ansnum -= num[1];

                if(j == 1) ansnum += num[2];
                else ansnum -= num[2];

                if(k == 1) ansnum += num[3];
                else ansnum -= num[3];

                if(ansnum == 7 && ans == ""){
                    ans += to_string(num[0]);
                    if(i == 1) ans += "+";
                    else ans += "-";
                    ans += to_string(num[1]);
                    if(j == 1) ans += "+";
                    else ans += "-";
                    ans += to_string(num[2]);
                    if(k == 1) ans += "+";
                    else ans += "-";
                    ans += to_string(num[3]);
                    ans += "=7";
                    break;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}