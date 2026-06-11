#include <bits/stdc++.h>
using namespace std;
std::map<string, int> num;
long long int n;
void dfs(string s) {
    if (num[s]==1) {
        return;
    } else if (stoll(s)>n) {
        return;
    } else {
        num.emplace(s,1);
        for (int i=3;i<=7;i+=2) {
            dfs(s+to_string(i));
        }
    }
}

int main(void){
    cin>>n;
    dfs("0");
    int cnt=0;
    for (auto itr=num.begin();itr!=num.end();itr++) {
        string tmp=itr->first;
        if (stoll(tmp)<=n) {
            int count3=0,count5=0,count7=0;
            for (int j=0;j<tmp.size();j++) {
                if (tmp[j]=='3') {
                    count3=1;
                } else if (tmp[j]=='5') {
                    count5=1;
                } else if (tmp[j]=='7') {
                    count7=1;
                }
                if (count3==1&&count5==1&&count7==1) {
                    cnt++;
                    break;
                }
            }
        }
    }
    cout<<cnt<<endl;
}