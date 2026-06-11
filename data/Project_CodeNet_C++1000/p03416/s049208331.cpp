#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   int a,b;
   cin >> a >> b;
   int cnt = 0;
   for(int i=a; i<=b; i++)
   {
      // stringstream gk ;
       int num = i;

     ostringstream str1;


    str1 << num;


    string geek = str1.str();
    bool mrk = 0;
    for(int r=0,j=geek.size()-1; r<=j; r++,j--)
    {
        if(geek[r]==geek[j])continue;
        else {mrk=1;break;}
    }
  if(!mrk)cnt++;

   }
   cout << cnt << endl;
}
