#include <bits//stdc++.h>
#define rep(i,n) for(int i = 0;i < n;i++)
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    bool ans=false;
    int n=s.size();
    if(s[0]=='A'){
        int cnt=0;
        for(int i=2;i<n-1;i++){
            if(s[i]=='C')cnt++;
        }
        if(cnt==1){
            int j=0;
            for(int i=1;i<n;i++){
                if(s[i]<'a')j++;
            }
            if(j==1)ans=true;
        }
    }
    if(ans)cout<<"AC"<<endl;
    else cout<<"WA"<<endl;
    return 0;
}