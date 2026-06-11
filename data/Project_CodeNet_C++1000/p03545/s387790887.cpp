#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    string abcd;
    cin >> abcd;
    for(int bit=0; bit < (1<<3); ++bit){
        vector<char> sign(3);
        bitset<3> s(bit);
        int ans = (int)(abcd[0]-'0');
        for(int i=0; i<3; ++i){
            if(s.test(i)){
                ans+=(int)(abcd[i+1]-'0');
                sign[i] = '+';
            }
            else{
                ans-=(int)(abcd[i+1]-'0');
                sign[i] = '-';
            }
        }
        if(ans==7){
            for(int i=0; i<3; ++i){
                cout << abcd[i] << sign[i];
            }
            cout << abcd[3] << "=7" << endl;
            return 0;
        }
    }
    return 0;
}
