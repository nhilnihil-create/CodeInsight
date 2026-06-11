#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define MAX 100000
void inarray(int a[], int n){
    for(int i = 0; i < n; i++) cin >> a[i];
}

int main(){
    int n,a,b,c,d; cin >> n >> a >> b >> c >> d;
    a--; b--; c--; d--;
    // string s; cin >> s;
    char s[n];
    for(int i = 0; i < n; i++) cin >> s[i];
    int ma = INT_MIN, w =0;
    for(int i = a; i < c-1; i++){
        if(s[i] == s[i+1] && s[i] == '#'){
            cout << "No" << endl; return 0;
            // 飛べないとこが二つ続く
        }
    }
    for(int i = b; i < d-1; i++){
        if(s[i] == s[i+1] && s[i] == '#'){
            cout << "No" << endl; return 0;
            // 飛べないとこが二つ続く
        }
    }
    if(c > d){
        for(int i = b; i <= d; i++){
            // cout << s[i-1] << " " << s[i] << " " <<s[i+1] << endl;
            if(s[i-1] == s[i] && s[i] == s[i+1] && s[i] == '.'){
                cout << "Yes" << endl; return 0;
            }
        }
        cout << "No" << endl; 
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}