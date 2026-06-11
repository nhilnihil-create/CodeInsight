#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    double cookie,segundos,tempo;
    int produzidos = 0;

    cin >> segundos >> cookie >> tempo;

    if (segundos > tempo)
    {
        cout << produzidos << endl;
    }
    for (double i = segundos ; i < tempo + 0.5 ; i += segundos)
    {
        produzidos += cookie;

    }
    if(produzidos != 0)
    {
        cout << produzidos << endl;
    }
    return 0;
}