#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int> > l,r;
bool used[100005];
int n;

int main(){
    scanf("%d",&n);
    for (int x = 0; x<n; x++){
        int a,b;
        scanf("%d%d",&a,&b);
        l.push_back({a,x});
        r.push_back({b,x});
    }
    sort(l.begin(),l.end(),greater<pair<int,int> >());
    sort(r.begin(),r.end());
    long long try1 = 0;
    int curpos = 0;
    for (int x = 0; x<n; x++){
        if (!used[l[x].second]) {
            used[l[x].second] = true;
            if (l[x].first>curpos){
                try1 += l[x].first-curpos;
                curpos = l[x].first;
            }
        }
        if (!used[r[x].second]){
            used[r[x].second] = true;
            if (r[x].first<curpos){
                try1 += curpos-r[x].first;
                curpos = r[x].first;
            }
        }
    }
    try1 += abs(curpos);
    long long try2 = 0;
    curpos = 0;
    memset(used,false,sizeof(used));
    for (int x = 0; x<n; x++){
        if (!used[r[x].second]){
            used[r[x].second] = true;
            if (r[x].first<curpos){
                try2 += curpos-r[x].first;
                curpos = r[x].first;
            }
        }
        if (!used[l[x].second]) {
            used[l[x].second] = true;
            if (l[x].first>curpos){
                try2 += l[x].first-curpos;
                curpos = l[x].first;
            }
        }
    }
    try2 += abs(curpos);
    printf("%lld",max(try1,try2));



}
