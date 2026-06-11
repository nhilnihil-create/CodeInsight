#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    string s;
    cin>>s;
    int n=s.size();
    bool pos=true;
    if(s[n-1]=='1' || s[0]=='0') pos=false;
    for(int i=0;i<n-1;i++){
        if(s[i]=='1' && s[n-2-i]=='0') pos=false;
    }
    if(!pos){
        cout<<-1<<endl;
        return 0;
    }
    queue<int> qu;
    for(int i=0;i<n;i++){
        if(s[i]=='1')qu.push(i+1);
    }
    qu.push(n);
    for(int i=1;i<n;i++){
        if(i==qu.front()){
            qu.pop();
        }
        cout<<i<<" "<<qu.front()<<endl;
    }

}