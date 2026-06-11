    //Abhigyan's Code:
             
    //YOU DON'T DARE TO COPY :) 

    #include<bits/stdc++.h>
    using namespace std;
    typedef long long int ll;
    typedef unsigned long long int ull;
    #define checker cout<<"CHECKED" 
    #define modulo 1000000007
  
    int main()
    {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
     
    ll n , k ;
    cin >> n>> k ;

    vector<ll> vec(n) ;
    
    for(auto &z : vec)
      cin >> z ;

    bool dp[k+1] = {false} ;

    for(ll i = 1 ; i <= k ;i++)
    {
      for(ll j = 0; j < n ; j++)
      {
        if(i - vec[j] < 0 )
          break ;
        if(dp[i - vec[j]] == false )
        {
          dp[i] = true ;
          break ;
        }
      }
    }

    if(dp[k])
      cout << "First";
    else
      cout << "Second";


    return 0;

   }   