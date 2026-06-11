#include <iostream>
using namespace std;


int main() {
    int N;
	string S;
    cin >> N >> S  ;
int reR=0;
int reB=0;
for(int i=0;i<S.length();i++){
if(S[i]=='R')reR++;
else
reB++;
}
if(reR>reB)
    cout << "Yes";
else
    cout << "No";




return 0;
}