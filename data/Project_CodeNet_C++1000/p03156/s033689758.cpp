#include<iostream>
using namespace std;
int main(){
    int N,A,B,P,sum=129;
    int S[3]={0};
    cin >> N;
    cin >> A >> B;
    for(int i=0;i<N;i++){
        cin >> P;
        if(P<=A)S[0]++;
        else if(P>=B+1)S[2]++;
        else S[1]++;
    }
    for(int j=0;j<3;j++){
        if(S[j]<sum)sum=S[j];
    }
    cout << sum << endl;
}