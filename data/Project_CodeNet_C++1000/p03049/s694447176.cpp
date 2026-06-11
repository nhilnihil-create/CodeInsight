#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P  = pair<int,int>;
using v  = vector<int>;
using vv = vector<v>;

int main(){
    int n; cin >> n;
    
    int count = 0;
    int a=0,b=0,ba=0;
    string s;
    for(int i=0; i<n; i++){
        cin >> s;
        if(s[0]=='B' && s[s.size()-1]=='A')
            ba++;
        else if(s[0]=='B')
            b++;
        else if(s[s.size()-1]=='A')
            a++;
        
        for(int j=1; j<s.size(); j++){
            if(s[j-1]=='A' && s[j]=='B')
                count++;
        }
    }
    
    if(ba==0)count += min(a,b);
    if(ba!=0){
        if(b==0 && a==0)
            count += ba-1;
        else
            count += ba + min(a,b);
    }
    
    cout << count << endl;
    return 0;
}