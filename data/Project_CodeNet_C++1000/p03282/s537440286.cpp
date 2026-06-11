#include <bits/stdc++.h>
#define DAYS 5000000000000000
using namespace std;

int main(void){
    string s;
    long long int k, tmp, cnt = 0;
    cin >> s >> k;
    for (int i=0; i<s.size(); i++){
        if (s[i] == '1') cnt++;
        else{
            for (int j=1; j<=DAYS; j++){
                tmp = pow(s[i] - '0', j);
                if (cnt + tmp >= k){
                    cout << s[i] << endl;
                    return 0;
                }
            }
            cnt += tmp;
        }
        if (cnt >= k){
            cout << s[i] << endl;
            return 0;
        }
    }
}