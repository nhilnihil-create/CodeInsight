#include<bits/stdc++.h>
using namespace std;

void read(int &x) {
    x=0;int f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';x*=f;
}

void print(int x) {
    if(x<0) putchar('-'),x=-x;
    if(!x) return ;print(x/10),putchar(x%10+48);
}
void write(int x) {if(!x) putchar('0');else print(x);putchar('\n');}

#define lf double
#define ll long long 

#define pii pair<int,int >
#define vec vector<int >

#define pb push_back
#define mp make_pair
#define fr first
#define sc second

#define data asd09123jdf02i3h

#define FOR(i,l,r) for(int i=l,i##_r=r;i<=i##_r;i++)

const int maxn = 1e6+10;
const int inf = 1e9;
const lf eps = 1e-8;
const int mod = 1e9+7;

int n,a[maxn];

int check(int x) {
    map<int,int > t;
    for(int i=1;i<=n;i++) {
        if(a[i]<=a[i-1]) {
            auto p=t.lower_bound(a[i-1]+1);// cerr<<"OK"<<endl;
            while(p!=t.end()) {auto q=p;p++;t.erase(q);}
            t[a[i]]++;
            int v=a[i];
            while(t[v]==x) t[v]=0,t[v-1]++,v--;
            // cerr<<"?"<<endl;
            if(v<=0) return 0;
        }
    }
    return 1;
}

int main() {
    read(n);int bo=1;
    for(int i=1;i<=n;i++) {
        read(a[i]);
        if(a[i]<=a[i-1]) bo=0;
    }
    if(bo) return puts("1"),0;
    int l=2,r=n,ans=n;
    while(l<=r) {
        int mid=(l+r)>>1;
        if(check(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    write(ans);
    return 0;
}
