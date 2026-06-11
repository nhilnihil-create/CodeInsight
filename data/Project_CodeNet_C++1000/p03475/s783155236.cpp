#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

int main(void){
    int n;
    cin >> n;
    vector<double> c(n), s(n), f(n);
    for(int i=1; i<=n; i++){
        cin >> c[i] >> s[i] >> f[i];
    }

    for(int i=1; i<=n; i++){
        double time = 0;
        time += s[i] + c[i];
        for(int j=i+1; j<=n-1; j++){
            double wait;
            if(time < s[j]){
                wait = s[j] - time;
            }
            else{
                wait = ceil(time/f[j])*f[j] - time;
            }
            time += wait;
            time += c[j];
        }
        cout << int(time) << endl;
    }
    return 0;
}