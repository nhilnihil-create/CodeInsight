#include<iostream>
#include<string>
using namespace std;

int main() {
    long mod = 1e9+7;
    string S;
    cin>>S;
    long Anum = 0, ABnum = 0, ABCnum = 0;
    long patturn = 1;
    for(int i=0;i<S.size();++i){
        if(S[i]=='A'){
            Anum += patturn;
        }
        if(S[i]=='B'){
            ABnum += Anum;
        }
        if(S[i]=='C'){
            ABCnum += ABnum;
        }
        if(S[i]=='?'){
            ABCnum = ABCnum * 3 + ABnum;
            ABnum = ABnum * 3 + Anum;
            Anum = Anum * 3 + patturn;
            patturn *= 3;
        }
        Anum %= mod;
        ABnum %= mod;
        ABCnum %= mod;
        patturn %= mod;
    }
    cout<<ABCnum<<endl;
}
