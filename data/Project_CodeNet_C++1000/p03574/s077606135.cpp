/** author: __nishad__ **/
//#pragma GCC optimize(2)
//#pragma GCC optimize(3, "Ofast", "inline")
#include<bits/stdc++.h>
using namespace std;


typedef long long ll ;
typedef vector<ll> vll ;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define precision(k) cout<<setprecision(k)<<fixed;
#define loop(i,a,b) for(int i=(a);i<(b);++i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define getpos(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define unq(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define pb push_back
#define mp make_pair
#define pi 3.14159265358979323
#define endl "\n"

int main()
{
    IOS;

    int o, p;
    char ch;
    cin>>o>>p;

    int arr[o][p];

    loop(i, 0, o){
        loop(j, 0, p){
            cin>>ch;
            if(ch == '.')
                arr[i][j] = 1;
            else if(ch == '#')
                arr[i][j] = 11;
        }
    }

    loop(i, 0, o){
        loop(j, 0, p){
            if(arr[i][j] == 1){
            int count = 0;
                for(int m = i-1; m <=i+1; m++){
                    for(int n = j-1; n <= j+1; n++){
                        if(m>-1 && n>-1 && m<o && n<p){
                            if(arr[m][n] == 11)
                                count++;
                            else
                                count = count;
                        }
                    }
                }
                arr[i][j] = count;
            }

        }
    }

    loop(i, 0, o){
        loop(j, 0, p){
            if(arr[i][j] == 11)
                cout<<"#";
            else
                cout<<arr[i][j];
        }
        cout<<endl;
    }


}



























