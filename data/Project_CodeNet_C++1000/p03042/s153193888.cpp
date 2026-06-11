
#include<bits/stdc++.h>
using namespace std;

int ans[305][305];

int main()
{


     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
  /*  #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
   */
  string nish;
  cin>>nish;
  int siz=nish.size();

  int total1=(nish[0]-'0')*10+(nish[1]-'0');
  int total2=(nish[2]-'0')*10+(nish[3]-'0');
  if(total1>0 && total1<=12 && total2>0 && total2<=12 )
  {
    cout<<"AMBIGUOUS"<<endl;
  }
  else if(total1>0 && total1<=12)
  {
    cout<<"MMYY"<<endl;
  }
  else if(total2>0 && total2<=12)
    cout<<"YYMM"<<endl;
  else
    cout<<"NA"<<endl;


   return 0;
    
}