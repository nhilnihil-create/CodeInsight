#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define all(a) a.begin(),a.end()
#define endl '\n'
#define ull unsigned long long
#define y1 ljhadglkjsadf
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define iter set< pair<int,int> >::iterator
#define iter1 set<int>::iterator
#define int long long
using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

template<class T>
using ordered_multiset=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rnd1(chrono::steady_clock::now().time_since_epoch().count());

//find_by_order
//order_of_key

const int N=2e5+7;
const int inf=1e18+1e9;
const int mod=1e9+7;
const ld eps=1e-9;

//const int MAX_MEM=4e8;
//int mpos=0;
//char mem[MAX_MEM];
//
//inline void * operator new(size_t n){
//    char *res=mem+mpos;
//    mpos+=n;
//    if (mpos>=MAX_MEM){
//        cout<<"BAD"<<endl;
//        exit(0);
//    }
//    return (void*)res;
//}
//
//inline void operator delete(void *) {}

int n;
int a[N];
vector<int>b;

bool check(int x)
{
    if (x==1){
        if (b.size()>0)return 0;
        return 1;
    }
    set< pair<int,int> >setik;
    for (int i=2;i<=n;++i){
        if (a[i]<=a[i-1]){
            while(true && setik.size()>0){
                iter it=setik.end();
                --it;
                pair<int,int>t=(*it);
                if (t.ff>a[i])setik.erase(it);
                else {
                    break;
                }
            }
            int cur=a[i];
            while(setik.size()>0){
                iter it=setik.end();
                --it;
                pair<int,int>t=(*it);
                if (t.ff==cur && t.ss==x-1){
                    setik.erase(it);
                    --cur;
                }
                else {
                    break;
                }
            }
            if (cur==0){
                return 0;
            }
            else {
                if (setik.size()>0){
                    iter it=setik.end();
                    --it;
                    pair<int,int>t=(*it);
                    if (t.ff==cur){
                        setik.erase(it);
                        t.ss++;
                        setik.insert(t);
                    }
                    else {
                        setik.insert({cur,(int)1});
                    }
                }
                else {
                    setik.insert({cur,1});
                }
            }
        }
    }
    return 1;
}

main ()
{
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=2;i<=n;++i){
        if (a[i]<=a[i-1]){
            b.pb(a[i]);
        }
    }
    int l=1;
    int r=N-1;
    while(l<r){
        int mid=(l+r)/2;
        if (check(mid))r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
}
//1
//3 15
//1 4
//3 5
