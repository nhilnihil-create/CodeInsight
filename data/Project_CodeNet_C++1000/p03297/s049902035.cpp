    #include<bits/stdc++.h>
    using namespace std;
    # define ll unsigned long long 

  
    
    int main(){
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int t;
        cin>>t;
        while(t--){
            ll a,b,c,d;
            cin>>a>>b>>c>>d;
            if(a<b){
                cout<<"No"<<endl;
                continue;
            }
            if(a>=b && b>d){
                cout<<"No"<<endl;
                continue;
            }

            if(a>=b && b<=d && c>=b){
                cout<<"Yes"<<endl;
                continue;
            }
            else{
                ll g=__gcd(b,d);
                if(b-g+a%g > c){
                    cout<<"No"<<endl;
                }
                else{
                    cout<<"Yes"<<endl;
                }
            }
          

        }

    }