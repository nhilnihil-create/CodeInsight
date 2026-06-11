//XXFESTIVAL
#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    string sample="FESTIVAL";
    cin>>S;
    int find_fes=S.rfind(sample);
    for(int i=0;i<find_fes;i++)cout<<S[i];
    cout<<endl;
    return 0;
}