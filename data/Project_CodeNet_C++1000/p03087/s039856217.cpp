#include <bits/stdc++.h>
using namespace std;
int main(){
    string S;
    int N,Q;
    vector <long long> l(1000000),r(1000000);
    vector <long long> s(1000000,0);    
    vector <long long> t(1000000,0);
    cin >> N >> Q >> S;
    for(int i=0;i<Q;i++){
        cin >>l.at(i)>>r.at(i);
    }
    for(int i=0;i<N-1;i++){
        if(S.at(i)=='A'&&S.at(i+1)=='C'){
            s.at(i)=1;
        }
    }
    for(int i=0;i<N-1;i++){
        t.at(i+1)=s.at(i)+t.at(i);
    }
    for(int i=0;i<Q;i++){
        cout << t.at(r.at(i)-1)-t.at(l.at(i)-1)<<endl;
    }
  return 0;
}
