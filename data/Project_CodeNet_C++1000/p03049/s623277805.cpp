#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int firstB = 0;
    int lastA = 0;
    int AB = 0;
    string s;
    long ans = 0;
    for(int i=0;i<n;i++){
        cin >> s;
        if(s[0] == 'B' && s[s.length()-1]=='A')AB++;
        else{
            if(s[0]=='B')firstB++;
            if(s[s.length()-1]=='A')lastA++;
        }
        for(int j=0;j<s.length()-1;j++){
            if(s.substr(j,2)=="AB")ans++;
        }
        
        
    }
    if(AB>=1){
            ans += AB-1;
            if(firstB >0){
                ans++;
                firstB--;
            }
            if(lastA > 0){
                ans++;
                lastA--;
            }
        }
    cout << ans+min(firstB,lastA)<<endl;
    
}
