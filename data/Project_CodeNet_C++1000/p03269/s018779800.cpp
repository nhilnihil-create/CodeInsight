#include<bits/stdc++.h>
using namespace std;
#define y1 A2Dalek
#define y0 Cyberman
#define yn RoseTyler
#define j1 JackHarkness
#define fs first
#define sd second
const int N=2e5;
const int oo=1e9+5;
int du[]={-1,0,0,1};
int dv[]={0,-1,1,0};
const long long mod=1e9+7;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
long long sqr(long long x) {return x*x;}
int getbit(int state, int i) {return ((state>>i)&1);}

int get(int x)
{
    int dem=1;
    while (x)
    {
        if (x%2==0) x--;
        x/=2;
        dem++;
    }
    return dem;
}
int n,L;
vector<iii> q;
int main()
{
	//freopen("All Your Paths are Different Lengths.inp","r",stdin);
	//freopen("All Your Paths are Different Lengths.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin>>L; L--;
    n=get(L);
    int k=n;
    while (L)
    {
        if (L%2==0)
        {
            q.push_back(iii(ii(1,k),L));
            L--;
            q.push_back(iii(ii(k-1,k),0));
            q.push_back(iii(ii(k-1,k),L/2+1));
            L=L/2;
        } else
        {
            q.push_back(iii(ii(k-1,k),0));
            q.push_back(iii(ii(k-1,k),L/2+1));
            L=L/2;
        }
        k--;
    }
    cout<<n<<" "<<q.size()<<endl;
    for (int i=0;i<q.size();i++)
    {
        cout<<q[i].fs.fs<<" "<<q[i].fs.sd<<" "<<q[i].sd<<endl;
    }
	return 0;
}
