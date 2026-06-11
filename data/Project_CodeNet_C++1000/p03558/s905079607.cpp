#include<bits/stdc++.h>

#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple

using namespace std;

bool mark[100010];
bool usao[100010];
int minSum[100010];
set<tuple<int, int, int>> veze;
int k;

void dodaj(int sum, int cvor, int cif)
{
    //mark[cvor] = true;
    veze.insert(mt(sum, cvor, cif));
}

void bfs()
{
    while(!veze.empty())
    {
        set<tuple<int, int, int>>::iterator it = veze.begin();
        tuple<int, int, int> prim = *it;
        int kol = get<0>(prim);
        int cvor = get<1>(prim);
        int cif = get<2>(prim);
        
        veze.erase(*it);
        if(!usao[cvor])
        {
            mark[cvor] = true;
            usao[cvor] = true;
            minSum[cvor] = kol;
            if(cvor == 0) return;
            int nxtCvor = (10*cvor) % k;
            if(!usao[nxtCvor]) dodaj(kol, nxtCvor, 0);
            nxtCvor = (cvor + 1) % k;
            if(cif != 9)
                if(!usao[nxtCvor]) dodaj(kol + 1, nxtCvor, cif + 1);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> k;
    veze.insert(mt(1, 1, 1));
    bfs();
    cout << minSum[0];

    return 0;
}