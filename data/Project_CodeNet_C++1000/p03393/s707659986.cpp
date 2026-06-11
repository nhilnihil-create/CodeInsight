#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin>>s;
    std::map<char, int> map;
    for (int i=0;i<s.size();i++) {
        map[s[i]]++;
    }
    std::deque<char> alpha;
    for (int i=97;i<123;i++) {
        char c=i;
        alpha.emplace_back(c);
    }
    reverse(s.begin(),s.end());
    int flag=0;
    for (int i=0;i<alpha.size();i++) {
        if (map[alpha[i]]==0) {
            s=alpha[i]+s;
            flag=1;
            break;
        }
    }
    if (flag==0) {
        while (s.size()!=0) {
            int tmp=s[0]-96;
            map[s[0]]--;
            s.erase(0,1);
            for (int i=tmp;i<alpha.size();i++) {
                if (map[alpha[i]]==0) {
                    s=alpha[i]+s;
                    flag=1;
                    break;
                }
            }
            if (flag==1) {
                break;
            }
        }
    }
    if (flag==1) {
        reverse(s.begin(),s.end());
        cout<<s<<endl;
    } else {
        cout<<-1<<endl;
    }
}