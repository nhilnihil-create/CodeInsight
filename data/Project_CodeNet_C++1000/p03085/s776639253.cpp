#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF=1001001001;

long long int answ(long long int x){
  if(x==1) return 1;
  if(x>1) return 2*answ(x/2)+1;
}
int main() {
    char b;
    cin>>b;
    if(b=='A') cout<<"T"<<endl;
    if(b=='T') cout<<"A"<<endl;
    if(b=='G') cout<<"C"<<endl;
    if(b=='C') cout<<"G"<<endl;



}