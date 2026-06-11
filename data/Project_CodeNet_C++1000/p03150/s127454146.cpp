#include<bits/stdc++.h>
using namespace std;

int main(){
    string s,b="keyence"; cin>>s;
    int n=s.size();
    for(int i=0; i<n; i++) {
        if(s[i]==b[0]){
            bool flag=1;
            int j = 1;
            while(flag && j<7){
                if(s[i+j]==b[j])j++;
                else flag=0;
            }
            if((i==0 && j==7) || (i==n-7 && j==7)){
                cout << "YES" << endl;
                return 0;
            }
            for(int k=i+j+1; k<n; k++){
                if(s.substr(k,7-j)==b.substr(j,7-j) &&(i==0&&k+7-j-1==n-1)){
                    cout << "YES" << endl;
                    return 0;
                }
            }
        i +=j-1;
        }
    }
    cout << "NO" << endl;
    return 0;
}