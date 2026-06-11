/*THERE'S ALWAYS SOMETHING , NOT THAT YOU WOULD UNDERSTAND . YOU ARE LIKE MY SISTER ,
 EVERYTHING ALWAYS CAME EASY TO HER .
 SHE'S A FIRE BENDING PRODIGY AND EVERY ONE ADORE HER . MY FATHER SAYS
 SHE WAS BORN LUCKY ,HE SAYS I WAS LUCKY TO BE BORN . I DON'T NEED LUCK THOUGH .
 I DON'T WANT IT . I'VE ALWAYS HAD TO STRUGGLE AND FIGHT
 AND THAT'S MADE ME STRONG . IT MADE ME WHO I AM .*/
#include<bits/stdc++.h>
using namespace std;
string solve(vector<int>& v,int k)
{
    bool dp[k+1];
    memset(dp,0,sizeof dp);
    for(int i=1;i<=k;i++)
    {
        for(int move:v)
        {
            if(move>i)continue;
            if(dp[i-move]==0)
                dp[i]=1;
        }
    }
    return dp[k]?"First":"Second";
}
main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<solve(v,k);
}
/* WHATEVER DOESNT KILL ME ONLY MAKES ME STRONGER .*/
