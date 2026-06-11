#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    string S;
    cin>>S;
    int n=S.size();
    
    if(n>9) cout<<"NO"<<endl;
    else if(n==9){
        if(S=="AKIHABARA") cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else if(n==8){
        if(S == "KIHABARA" || S == "AKIHBARA" || S == "AKIHABRA" || S == "AKIHABAR") cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else if(n==7){
        if(S == "KIHBARA" || S == "KIHABRA" || S == "KIHABAR" || S == "AKIHBRA" || S == "AKIHBAR" || S == "AKIHABR") cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else if(n==6){
        if(S == "AKIHBR" || S == "KIHABR" || S == "KIHBAR" || S == "KIHBRA") cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else if(n==5){
        if(S == "KIHBR") cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else cout<<"NO"<<endl;
    
}