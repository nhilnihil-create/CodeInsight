#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<string, string> P;

int main(){
    int N;
    cin >> N;
    map<P, long> ml, mr;
    string s;
    cin >> s;
    string sl(&s[0], &s[N]);
    string sr(&s[N], &s[2*N]);
    reverse(sr.begin(), sr.end());
    for(int i = 0; i < (1<<N); i++){
       string slb, slr, srb, srr;
       for(int j = 0; j < N; j++ ){
           if((1<<j)&i){
               slr += sl[j];
               srr += sr[j];
           }else{
               slb += sl[j];
               srb += sr[j];
           }
       }
       P pl = P(slr, slb);
       if(ml.find(pl) == ml.end()){
           ml[pl] = 1;
       }else{
           ml[pl]++;
       }
       P pr = P(srr, srb);
       if(mr.find(pr) == mr.end()){
           mr[pr] = 1;
       }else{
           mr[pr]++;
       }
    }
    long ans = 0;
    for(auto iter:ml){
        //cout << iter.first.first << ' ' << iter.first.second << ' ' << iter.second << endl;
        if(mr.find(iter.first) != mr.end()){
            long add = mr[iter.first]*iter.second;
            ans += add;
            //cout << add << endl;
        }
    }
    cout << ans << endl;
}