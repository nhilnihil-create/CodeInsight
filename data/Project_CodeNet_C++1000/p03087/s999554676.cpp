#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> l(q),r(q);
    for(int i=0; i<q; i++){
        cin >> l.at(i) >> r.at(i);
        l.at(i)-=2;
        r.at(i)--;
    }
    vector<int> count(n,0);
    for(int i=0; i<n-1; i++){
        count.at(i+1) = count.at(i);
        if(s.at(i) == 'A' && s.at(i+1) == 'C') count.at(i+1)++; 
    }
    for(int i=0; i<q; i++){
        if(l.at(i) == -1) cout << count.at(r.at(i)) << endl;
        else{
            if(s.at(l.at(i)) == 'A' && s.at(l.at(i)+1) == 'C'){
                cout << count.at(r.at(i)) - count.at(l.at(i)) -1<< endl;
            }
            else{
                cout << count.at(r.at(i)) - count.at(l.at(i)) << endl;
            }
        }
    }
    cout << endl;

}