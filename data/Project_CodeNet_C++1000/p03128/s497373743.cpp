#include <bits/stdc++.h>
//#include <string>
using namespace std;


#define typeof(x) __typeof__(x)
#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest
#define max(a,b) (a<b?b:a)
//#define abs(x) (x<0?(-x):x) // big bug here if "-x" is not surrounded by "()"
#define IN(i,l,r) (l<i&&i<r) //the next for are for checking bound
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)
#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FIN(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFIN(i,L,R) for (int i = L; i >= R; i--)
#define getI(a) scanf("%d", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define g_s(n) int (n); scanf("%d",&(n)) //handy if the input is right after the definition of a variable
#define g_s2(n,m) int (n),(m); scanf("%d %d",&(n),&(m))
#define g_s3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k))
#define TESTS g_s(testow);while(testow--) //for multilple cases problems
#define whileZ int T; getI(T); while(T--) // the same as above
#define getS(x) scanf("%s", x) //get a char* string
#define MEM(a,x) memset(a,x,sizeof(a)) //set elements of array to some value
#define char2Int(c) (c-'0')
#define lastEle(vec) vec[vec.size()-1]
#define SZ(x) ((int)((x).size()))
#define REMAX(a,b) (a)=max((a),(b)) // set a to the maximum of a and b
#define REMIN(a,b) (a)=min((a),(b));
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) // traverse an STL data structure
#define ALL(c) (c).begin(),(c).end() //handy for function like "sort()"
#define PRESENT(c,x) ((c).find(x) != (c).end())
#define CPRESENT(c,x) (find(ALL(c),x) != (c).end())
#define ll long long //data types used often, but you don't want to type them time by time
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define IOS ios_base::sync_with_stdio(0); //to synchronize the input of cin and scanf
#define INF 1001001001
#define PI 3.1415926535897932384626
//for map, pair
#define mp make_pair
#define fi first
#define se second
// for debug
inline void pisz(int n) { printf("%d\n",n); }
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define printA(a,L,R) FIN(jk,L,R) cout << a[jk] << (jk==R?'\n':' ')
#define printV(a) printA(a,0,a.size()-1)
#define MAXN 10000
#define sf scanf
#define pf printf
//for vectors
#define pb push_back
typedef int elem_t;
typedef vector<int> vi;
typedef vector<string> vstr;
typedef vector<set<int> > vset;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vector<bool> > vvb;
typedef pair<int,int> ii;
typedef vector<ii> vii;
// directions
const int dr[4] = {-1,0,1,0};
const int dc[4] = {0,-1,0,1};
const int drr[8] = {-1,-1,0,1,1,1,0,-1};
const int dcc[8] = {0,-1,-1,-1,0,1,1,1};
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){F(i,0,SZ(t))s<<t[i]<<" ";return s; }

class UnionFind{
    private: vi rank,p;
    public: 
        UnionFind(int n){
            F(i,0,n)p.pb(i);
            rank.assign(n,1);
        }

        int findSet(int s){
            return (p[s]==s) ? s : (p[s]=findSet(p[s]));
        }

        bool isSameSet(int i,int j){
            return findSet(i)==findSet(j);
        }

        void unionSet(int i,int j){
            if(isSameSet(i,j))return;

            int x=findSet(i),y=findSet(j);
            if(rank[x]>rank[y]){
                p[y]=x;
                rank[x]+=rank[y];
            }
            else {
                p[x]=y;
                //if(rank[x]==rank[y])rank[y]++;
                rank[y] += rank[x];
            }
            
        }

        int sz(int x){
            int px=findSet(x);
            return rank[px];
        }
};


double x_y(int x1,int y1,int x2,int y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}


int n,m,A[10],cst[]={999999,2,5,5,4,5,6,3,7,6};
int dp[11000]; 

int rec(int ct){
    
    if(ct>n)return -99999999;
    //cout<<s<<ct<<n<<endl;
    if(ct==n)return 0;
  //  pf("JHH");
 // cout<<dp[ct][1];

    if(dp[ct]!=-1)return dp[ct];
    int &ret=dp[ct],ans=-99999999;

    F(i,1,10){
       // pf("JHH");
        if(!A[i])continue;
        // string xt= "";
        // xt += '0'+i;
        int iv= 1+rec(ct+cst[i]);
        //if(iv=="777773")cout<<iv<<endl;

        //cout<<iv<<"    SSS"<<endl;
        // if(iv.size()>ret.size())ret=iv;
        // else if(iv.size()==ret.size()&&iv>ret)ret=iv;
        ans=max(ans,iv);
    }
    return ret=ans;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int cn=0;
    //TESTS{
    getII(n,m);
    MEM(A,0);
    F(i,0,m){
        g_s(iv);
        A[iv]=1;
    }
    MEM(dp,-1);
    //dp.assign(11000,"000");   
    //dp.resize(11000); 
    // F(i,0,11000){
    //     dp[i].pb("000");
    // }
    int dg=rec(0),prev=0;
    string ans="";

    F(i,0,dg){
        FFIN(j,9,1){
            if(!A[j])continue;
            if(dp[prev+cst[j]]==dp[prev]-1){
               // pf("%d %d\n",dp[20],dp[15]);
                ans += ('0'+j);
                prev += cst[j];
                break;
            }
        }
    }
    FFIN(i,9,1){
        if(!A[i])continue;
        if(prev+cst[i]==n){
            ans += ('0'+i);
            break;
        }
    }

    cout<<ans<<endl;
   
    return 0;
}
