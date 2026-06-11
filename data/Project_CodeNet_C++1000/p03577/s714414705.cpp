    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int sum=s.size();
    for(int i=0;i<sum-8;i++){
    cout<<s[i];
    }
    cout<<'\n';
    return 0;
    }