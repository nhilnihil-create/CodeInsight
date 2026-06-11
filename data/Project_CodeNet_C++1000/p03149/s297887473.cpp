    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    int n[5];
    for(int i=0;i<4;i++) cin>>n[i];
    sort(n,n +4);
    if(n[0]==1&&n[1]==4&&n[2]==7&&n[3]==9) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
    return 0;
    }