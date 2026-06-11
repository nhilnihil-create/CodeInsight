#include <bits/stdc++.h>

using namespace std;

long long niz[55];
int steps = 0;
struct resenje
{
    int a;
    int b;
};
resenje res[1000];

void solve1(int n,long long factor,int fact_poz)
{
    for(int i = 0; i < n; i++)
    {
        if(i!=fact_poz)
        {
            niz[i] += factor;
            res[steps].a = fact_poz+1; res[steps].b = i+1;
            //cout<<fact_poz+1<<" "<<i+1<<endl;
            steps++;
        }
    }
}

void solve2(int n,bool incr)
{
    if(incr)
    {
        for(int i = 0; i < n-1; i++)
        {
            niz[i+1] = niz[i+1] + niz[i];
            res[steps].a = i+1; res[steps].b = i+2;
            //cout<<i+1<<" "<<i+2<<endl;
            steps++;
        }
    }
    else
    {
        for(int i = n-1; i >=1; i--)
        {
            niz[i-1] = niz[i]+niz[i-1];
            //cout<<i+1<<" "<<i<<endl;
            res[steps].a = i+1;
            res[steps].b = i;
            steps++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>> n;
    long long maxi = -1; long long mini = LONG_LONG_MAX;
    int maxi_poz = 0; int mini_poz = 0;

    for(int i = 0; i < n; i++)
    {
        cin>>niz[i];
        if(niz[i] > maxi) {maxi = niz[i]; maxi_poz = i;}
        if(niz[i] < mini) {mini = niz[i]; mini_poz = i;}
    }

    long long factor = 0;
    int fact_poz = 0; bool incr = true;
    if(maxi > abs(mini)) {factor = maxi; fact_poz = maxi_poz; incr = true;}
    else {factor = mini; fact_poz = mini_poz; incr = false;}

    solve1(n,factor,fact_poz);
    solve2(n,incr);

    //cout<<"factor "<<factor<<endl;
    cout<<steps<<endl;
    for(int i = 0; i < steps; i++)
    {
        cout<<res[i].a<<" "<<res[i].b<<endl;
    }

    //for(int i = 0; i < n; i++)
       // cout<< niz[i]<<endl;

    return 0;
}
