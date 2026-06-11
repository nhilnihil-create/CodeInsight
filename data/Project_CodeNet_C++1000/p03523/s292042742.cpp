#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()

int main(){
    
    string S;cin>>S;
    vector<string> T1={"KIHBR"},T2={"AKIHBR","KIHABR","KIHBAR","KIHBRA"},T3={"AKIHABR","AKIHBAR","AKIHBRA","KIHABAR","KIHABRA","KIHBARA"},T4={"AKIHABAR","AKIHABRA","AKIHBARA","KIHABARA"},T5={"AKIHABARA"};
    int N=S.size();
    if(N==5){
        bool check=true;
        for(int i=0;i<N;i++){
            if(S[i]!=T1[0][i]) check=false;
        }
        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }else if(N==6){
        bool check;
        for(int j=0;j<4;j++){
            check=true;
        for(int i=0;i<N;i++){
            if(S[i]!=T2[j][i]) check=false;
        }
            if(check) break;
        }
        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }else if(N==7){
        bool check;
        for(int j=0;j<6;j++){
            check=true;
            for(int i=0;i<N;i++){
                if(S[i]!=T3[j][i]) check=false;
            }
            if(check) break;
        }
        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }else if(N==8){
        bool check;
        for(int j=0;j<4;j++){
            check=true;
            for(int i=0;i<N;i++){
                if(S[i]!=T4[j][i]) check=false;
            }
            if(check) break;
        }
        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }else if(N==9){
        bool check=true;
            for(int i=0;i<N;i++){
                if(S[i]!=T5[0][i]) check=false;
            }
        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }else cout<<"NO"<<endl;
}
