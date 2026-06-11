#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{

int n;
cin >> n;
bool mrk = 0;
int lastx = 0 , lasty = 0 , lastt = 0;
for(int i=1; i<=n; i++)
{
    int x,y,t;
    cin >> t >> x >> y;
    int dif = abs(x-lastx)+abs(y-lasty);
    int td = t - lastt ;
   // cout << dif << endl;
     lastx = x;
     lasty = y;
     lastt = t;
    if(dif && td>=dif && td%dif==0)
    {

        continue;
    }
    else mrk = 1;

}
if(!mrk)cout << "Yes" << endl;
else cout << "No" << endl;

}
