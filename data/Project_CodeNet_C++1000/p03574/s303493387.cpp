#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int counter( string* a , int i,int j , int h , int w)
{

    int ans =0;
    if( i-1>=0 && a[i-1][j] =='#')
    {
        ans++;
    }
    if( i+1 <h && a[i+1][j] =='#')
    {
        ans++;
    }
    if( j-1 >=0 && a[i][j-1 ] =='#')
        ans++;
    if( j+1 <w && a[i][j+1 ] =='#')
        ans++;

    if( i-1 >=0 && j-1>=0 && a[i-1][j-1] =='#' )
        ans++;
    if( i-1 >=0 && j+1 < w && a[i-1][j+1] =='#' )
        ans++;
    if( i+1 <h && j-1>=0 && a[i+1][j-1] =='#' )
        ans++;
    if( i+1 <h  && j+1 < w && a[i+1][j+1] =='#' )
        ans++;
    return ans;

}
void printer( string* a , int i , int j , int h , int w)
{
    if( a[i][j] == '#')
    {
        cout<<"#";
    } else
    {
        cout<<counter( a,i,j,h,w);
    }
}

int main()
{
  int h,w;
  cin>>h>>w;
  string *a = new string[h];
  for(int i=0;i<h;i++)
  {
      cin>>a[i];
  }
  for(int i=0;i<h;i++)
  {
      for(int j=0;j<w;j++)
      {
          printer(a,i,j,h,w);
      }
      cout<<endl;
  }
}