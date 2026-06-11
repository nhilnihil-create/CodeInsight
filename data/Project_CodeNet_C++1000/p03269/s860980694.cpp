#include <bits/stdc++.h>

using namespace std;

struct way
{
    int x;
    int y;
    int z;
};

int need;
int lg,n;
vector<way>ans;

inline void print()
{
    cout<<n<<" "<<ans.size()<<"\n";
    for(auto &it:ans)
        cout<<it.x<<" "<<it.y<<" "<<it.z<<"\n";
    exit(0);
}

int capat;

inline int nou(int i)
{
    return capat+(1<<(i-1))-1;
}

inline void add(int i,int x)
{
    ans.push_back({i,n,x});
}

int main()
{
  ///  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>need;
    while(1<<(lg+1)<=need)
        lg++;
    n=lg+1;
    for(int i=1;i<n;i++)
    {
        ans.push_back({i,i+1,0});
        ans.push_back({i,i+1,(1<<(i-1))});
    }

    capat=(1<<lg);

    for(int i=n-1;i>=1;i--)
    {///continue;
        while(1)
        {
            int x=nou(i);
       ///     cout<<i<<" , "<<x-capat<<" - > "<<capat<<" : "<<x<<" ,"<<need<<"\n";
            if(x>=need)
                break;
         ///   cout<<"\t"<<capat<<" "<<x<<"\n";
            add(i,capat);
            capat=x+1;
        }
    }
   // cout<<capat<<"\n";
   // cout<<nou(2)<<"\n";

  ///  cout<<"\n";cout<<"\n";cout<<"\n";cout<<"\n";cout<<"\n";cout<<"\n";cout<<"\n";cout<<"\n";cout<<"\n";cout<<"\n";cout<<"\n";cout<<"\n";cout<<"\n";cout<<"\n";cout<<"\n";cout<<"\n";
    print();
    return 0;
}
