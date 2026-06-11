#include<bits/stdc++.h>
using namespace std;
#define filein freopen ("in.txt", "r", stdin)
#define fileout freopen ("out.txt", "w", stdout)
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << "time consumed : " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    //filein;
    //fileout;

    string str;
    cin >> str;
    int len=str.size();
    int ans=len;
    int temp;
    for(int i=0;i<len-1;i++)
    {
		if(str[i]!=str[i+1])
		{

			temp=max(len-i-1,i+1);
		    ans=min(temp,ans);

		}
    }
    printf("%d\n",ans);





}

