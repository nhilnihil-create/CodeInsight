#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, inc, dec;
    scanf("%d %d %d", &n, &inc, &dec);
    if(inc>n || dec>n){
        printf("-1\n");
        return 0;
    }
    bool swapped=false;
    if(inc<dec)
    {
        swap(inc,dec);
        swapped=true;
    }
    vector<int> v;
    for(int i=n-inc+1; i<=n; i++) v.push_back(i);
    int nb_times_done=0;
    if(dec!=1)
    {
        if(dec-1>=n-inc+1)
        {
            printf("-1\n");
            return 0;
        }
        int start=dec-1;
        int down_to=1;
        while(true)
        {
            for(int i=start; i>=down_to; i--) v.push_back(i);
            nb_times_done++;
            if(start==n-inc+1-1) break;
            down_to=start+1;
            start=min(start+dec-1, n-inc+1-1);
        }
    }
    else
    {
        if(inc != n)
        {
            printf("-1\n");
            return 0;
        }
    }
    if(nb_times_done>inc)
    {
        printf("-1\n");
        return 0;
    }
    if(swapped) reverse(v.begin(), v.end());
    for(int i=0; i<v.size(); i++)
    {
        if(i != 0) printf(" ");
        printf("%d", v[i]);
    }
    printf("\n");
    return 0;
}
