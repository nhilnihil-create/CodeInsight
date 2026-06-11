#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    int N;
    cin>>N;
    string S;
    int endA = 0, startB = 0, ABnum = 0, BAnum = 0;
    for(int i=0;i<N;++i){
        cin>>S;
        for(int j=0;j<S.size()-1;++j){
            if(S[j] == 'A' & S[j+1] == 'B') ABnum++;
        }
        if(S[0]=='B' & S[S.size()-1]!='A') startB++;
        if(S[S.size()-1]=='A' & S[0]!='B') endA++;
        if(S[0]=='B' & S[S.size()-1]=='A') BAnum++;
    }
    if(BAnum>0){
        if(endA>0 | startB>0){
            cout<<ABnum+min(endA, startB) + BAnum;
        }
        else {
            cout<<ABnum+(BAnum-1);
        }
    }
    else{
        cout<<ABnum+min(endA, startB)<<endl;
    }
}
