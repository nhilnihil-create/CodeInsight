#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

struct data_t {
    string str;
    int num;
    int index;
} ;

int main() {
    int n;
    cin >> n;
    vector<data_t> res(n);
    rep(i, n){
        cin >> res.at(i).str >>  res.at(i).num ;
        res.at(i).index = i+1;
    }
    sort(res.begin(), res.end(), [](const data_t &a, const data_t&b){
        return (a.str == b.str) ? (a.num > b.num ) : (a.str < b.str);  
    });                         //a.numがb.numより大きくなるように.   a.strがb.strより小さくなるように

    for_each(res.begin(), res.end(), [](const data_t &a){
       cout << a.index << endl;
    });
    return 0;
}
