#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin >> s;

    int ans = 0, pos = 0;
    char lbuf, rbuf;
    int lpos, rpos;
    lpos = 0;
    rpos = 1;
    vector<int> lpos_mem;
    while (rpos<s.size()){
        lbuf = s.at(lpos);
        rbuf = s.at(rpos);

        if (lbuf != rbuf){
            ans += 2;
            if(lpos_mem.size() != 0){
                rpos++;
                lpos = lpos_mem.at(lpos_mem.size()-1);
                lpos_mem.pop_back();
            }
            else{
                rpos += 2;
                lpos = rpos-1;
            }
        }
        else{
            lpos_mem.push_back(lpos);
            rpos++;
            lpos = rpos-1;
        }
    }
    cout << ans << endl;
    return 0;
}