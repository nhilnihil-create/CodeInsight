#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n, q;


int f(string s, vector<pair<char,char>> op) {

    if(!count(op.begin(), op.end(), make_pair(s[0],'L'))) {
        return 0;
    }
    
    int lef = 0, rig = n; //oooooxxx
    while(rig - lef > 1) {
        int mid = (lef + rig) / 2;
        int pos = mid;
        bool ok = false;
        for(int i = 0; i < q; i++) {
            if(op[i].first == s[pos]) {
                if(op[i].second == 'R' ? pos++ : pos--);
                if(pos < 0){ok = true;break;}
                if(pos >= n)break;
            }
        }
        (ok ? lef : rig) = mid;
    }
    return rig;
}


int main()
{
    string s;
    cin >> n >> q >> s;
    vector<pair<char,char>> op(q);
    for(int i = 0; i < q; i++)cin >> op[i].first >> op[i].second;

    int lef = f(s, op); //xxxoooで何個落ちるか
    reverse(s.begin(), s.end());
    for(int i = 0; i < q; i++)op[i].second = (op[i].second == 'R' ? 'L' : 'R');
    int rig = f(s, op); //xxxoooの右端


    cout << n - min(rig + lef, n) << endl;


}