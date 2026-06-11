#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod=1000000007;
double pi=3.14159265359;
ll f( pair <ll,ll> a , pair <ll,ll> b) // J'utilise cette fonction pour trier les points selon les abscisses croissants
{
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(50);

    ll n;
    cin>>n;
    vector < pair <ll,ll> > v; //pour stocker les points
    map < pair <ll,ll> , int > mp; // pour différencier entre les points rouges et bleus

    map < pair <ll,ll> , int > visited; // pour s'assurer qu'un point appartient à un seul friendly couple

    for(ll i=0;i<2*n;i++)
    {
        ll a,b;
        cin>> a>> b;
        v.push_back( make_pair(a,b) );
        if(i<n) mp[make_pair(a,b)]=1; // red point
        else mp[make_pair(a,b)]=2; // blue point
    }
    sort(v.begin(),v.end(),f); // sort des points selon l'abscisse croissant

    ll res=0; // contiendra le resultat

    for(ll i=2*n-1;i>=0;i--)
    {
        ll y=2*n+1; //initialisation
        ll x=2*n+1; //initialisation

        // les initialisations edhoukom bech nesta3malhom bech ntalla3 le point j li 3andou le plus petit ordonnées akber men l'ordonné mta3 i
        ll test=0;
        for(ll j=2*n-1;j>i;j--) // je suis sur que les points j ont un abscisse > i car le vecteur est maintenant trié
        {
            if(mp[v[i]]==1 && mp[v[j]]==2 && visited[v[j]]==0 && v[j].second < y && v[j].second > v[i].second) // point i lezmou rouge; point j lezmou bleu ; wnlawwej 3al point j li 3andou asgher ordonnée mebinet les points li 3andhom ordonnée akber mel ordonnée mta3 i.
            {
                test=1; // ki test=1 ma3neha c bn l9it point j yveriy les conditions, ema bech nlawwej 3al optimal ( li 3andou asgher ordonnée mebinet les points li 3andhom ordonnée akber mel ordonnée mta3 i. )
                y=v[j].second;
                x=v[j].first;
            }
        }
        if(test)
        {
            res++;
            visited[make_pair(x,y)]=1; // n7ottou visited bech me3adech nesta3mlou fi couple e5er
        }
    }

    cout<< res;



    return 0;
}
