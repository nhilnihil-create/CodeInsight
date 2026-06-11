#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i,n,init) for(ll i=init;i<(n);i++)
#define ll long long

struct pyst {
    int no;
    int p;
    int y;
    char ans[13];
};

bool comp1(const pyst& a, const pyst& b) {
    if (a.p != b.p) {
        return(a.p < b.p);
    }
    return(a.y < b.y);
}

bool comp2(const pyst& a, const pyst& b) {
    return(a.no < b.no);
}

int main()
{
    int n,m;
    int ans1, ans2;

    cin >> n >> m;
    vector<pyst> py(m);
    rep(i, m) {
        py[i].no = i;
        cin >> py[i].p >> py[i].y;
    }
    sort(py.begin(), py.end(), comp1);
    ans1 = ans2 = 0;
    rep(i,m) {
        if (py[i].p != ans1) {
            ans1 = py[i].p;
            ans2 = 1;
        }
        else {
            ++ans2;
        }
        sprintf(py[i].ans, "%06d%06d", ans1, ans2);
    }
    sort(py.begin(), py.end(), comp2);
    rep(i, m) {
        printf("%s\n", py[i].ans);
    }

    return(0);
}
