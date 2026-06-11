#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<string>
#include<functional>
using namespace std;
typedef	long long int ll;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    if(s[0] != '1' || s[n-2] != '1' || s[n-1] != '0'){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < n-1; i++){
        if(s[i] != s[n-2-i]){
            cout << -1 << endl;
            return 0;
        }
    }
    int v = 1;
    for(int i = 0; i < n-1; i++){
        if(i==0){
            v = 2;
            cout << 1 << ' ' << 2 << endl;
        }
        else if(s[i]=='0'){
            cout << v << ' ' << i+2 << endl;
        }
        else if(s[i]=='1'){
            cout << v << ' ' << i+2 << endl;
            v = i+2;
        }
    }
    return 0;
}