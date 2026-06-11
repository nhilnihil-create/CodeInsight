#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector<int>v(n);
    vector<int>c(n);

    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &c[i]);

    int sum = 0;
    for(int i = 0; i < n; i++){
        if(v[i] > c[i]){
            sum += (v[i] - c[i]);
        }
    }
    printf("%d\n",sum);


    return 0;
}
