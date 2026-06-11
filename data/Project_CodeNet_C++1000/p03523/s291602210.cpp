#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

int main(void){
    string s;
    cin >> s;

    ll f = 0;
    ll count = 0;
    rep(i, 0, s.size()){
        if(f == 0){
            if(s[i] == 'K'){
                f++;
                count = 0;
            }else if(s[i] != 'A'){
                cout << "NO" << endl;
                return 0;
            }else{
                count++;
                if(count > 1){
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
        else if(f == 1){
            if(s[i] == 'I'){
                f++;
                count = 0;
            }else if(s[i] != 'A'){
                cout << "NO" << endl;
                return 0;
            }else{
                count++;
                if(count > 0){
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
        else if(f == 2){
            if(s[i] == 'H'){
                f++;
                count = 0;
            }else if(s[i] != 'A'){
                cout << "NO" << endl;
                return 0;
            }else{
                count++;
                if(count > 0){
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
        else if(f == 3){
            if(s[i] == 'B'){
                f++;
                count = 0;
            }else if(s[i] != 'A'){
                cout << "NO" << endl;
                return 0;
            }else{
                count++;
                if(count > 1){
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
        else if(f == 4){
            if(s[i] == 'R'){
                f++;
                count = 0;
            }else if(s[i] != 'A'){
                cout << "NO" << endl;
                return 0;
            }else{
                count++;
                if(count > 1){
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
        else if(f == 5){
            if(s[i] != 'A'){
                cout << "NO" << endl;
                return 0;
            }else{
                count++;
                if(count > 1){
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }

    if(f != 5){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    return 0;
}

