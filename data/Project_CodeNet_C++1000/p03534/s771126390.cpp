/*Whose woods these are I think I know.
His house is in the village though;
He will not see me stopping here
To watch his woods fill up with snow.

My little horse must think it queer
To stop without a farmhouse near
Between the woods and frozen lake
The darkest evening of the year.

He gives his harness bells a shake
To ask if there is some mistake.
The only other sound’s the sweep
Of easy wind and downy flake.

The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
const int maxn= 100010;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int a=count(s.begin(),s.end(),'a');
    int b=count(s.begin(),s.end(),'b');
    int c=count(s.begin(),s.end(),'c');
    if((a==b&&abs(a-c)==1)||(a==c&&abs(a-b)==1)||(b==c&&abs(b-a)==1)||(a==b&&a==c))
        cout<<"YES";
    else
        cout<<"NO";
    cout<<endl;
}