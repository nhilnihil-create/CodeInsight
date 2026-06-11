#include <iostream>
#include <cmath>
#include<vector>
#include <algorithm>
#include <utility>
#include<stack>
#include<queue>
#include<map>
#include <fstream>
#include<set>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long


    /// 16 30


    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int h,w,n,sr,sc;
        string s,t;
//        int r[2],l[2],u[2],d[2];

        cin>>h>>w>>n;
        cin>>sr>>sc;
        sr--;
        sc--;
        cin>>s;
        cin>>t;
        int l=0,r=0,u=0,d=0;
        for( int i=n-1;i>=0;i-- ){
                if(l<0)l=0;
                if(r<0)r=0;
                if(u<0)u=0;
                if(d<0)d=0;

            if( s[i] == 'L'&& t[i]=='U' ) l++,d--;
            if( s[i] == 'L' && t[i] =='D' )l++,u--;
            if( s[i] == 'R' && t[i] =='U' )r++,d--;
            if( s[i] == 'R' && t[i] =='D' )r++,u--;

            if( s[i] == 'U'&& t[i]=='R' ) u++,l--;
            if( s[i] == 'U' && t[i] =='L' )u++,r--;
            if( s[i] == 'D' && t[i] =='R' )d++,l--;
            if( s[i] == 'D' && t[i] =='L' )d++,r--;

            if( s[i] == 'R' && t[i] =='R' )r++,l--; /// prvo bilo samo r++
            if( s[i] == 'L' && t[i] =='L' )l++,r--;
            if( s[i] == 'U' && t[i] =='U' )u++,d--;
            if( s[i] == 'D' && t[i] =='D' )d++,u--;

            /// ovo tek na kraju dodajem, jer sam skonto da ipak mora
            if( s[i] == 'R' && r==0 )r++;
            if( s[i]=='L' && l==0 ) l++;
            if( s[i] =='U'&&u==0 ) u++;
            if( s[i]=='D'&&d==0 )d++;

            if( r == w || l == w || d==h || u==h ){
                    cout<<"NO"<<endl;
                    return 0;
                }
        }

        int levo = sc+1, desno=w-sc, gore=sr+1,dole=h-sr;
        if( levo > l && desno > r && gore > u && dole > d ){
            cout <<"YES"<<endl;
        }
        else cout<<"NO"<<endl;

    return 0;
    }



















