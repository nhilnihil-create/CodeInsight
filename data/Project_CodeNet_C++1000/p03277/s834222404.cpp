#include <bits/stdc++.h>

using namespace std;

const int max_n = 1e5 + 5;

int sumy[max_n], tab[max_n], n, drzewo[6 * max_n], rozmiar;

void aktualizuj(int x){
    drzewo[x]++;
    if (x > 1)
        aktualizuj(x / 2);
}

int znajdz(int a, int b, int p, int k, int x){
    if (p > b || k < a)
        return 0;
    if (a <= p && b >= k)
        return drzewo[x];
    int lewa = znajdz(a, b, p, (p + k) / 2, x * 2);
    int prawa = znajdz(a, b, (p + k) / 2 + 1, k, x * 2 + 1);
    return lewa + prawa;
}

bool sprawdz(int x){
    for (int i = 1; i < rozmiar * 2; i++)
        drzewo[i] = 0;
    long long wynik = 0;
    aktualizuj(rozmiar + n + 0);
    for (int i = 1; i <= n; i++){
        if (tab[i] >= x)
            sumy[i] = sumy[i - 1] + 1;
        else
            sumy[i] = sumy[i - 1] - 1;
        wynik += (long long)znajdz(0, n +  sumy[i], 0, rozmiar - 1, 1);
        aktualizuj(rozmiar + n + sumy[i]);
        //if (x == 1e9 / 2)
        //    cout << sumy[i] << "\n";
    }
    long long xd = (long long)n * (long long)(n - 1)/ 2 + (long long)n;
    //i//f (x == 1e9 / 2)
    //    cout << wynik << " " << xd << "\n";
    if (wynik >= (long long)xd / 2 + (long long)xd % 2)
        return true;
    return false;
}

int bin_search(){
    int poczatek = 0, srodek, koniec = 1e9, wynik = tab[0];
    while (poczatek <= koniec){
        srodek = (poczatek + koniec) / 2;
        if (sprawdz(srodek)){
            poczatek = srodek + 1;
            wynik = srodek;
        }
        else
            koniec = srodek - 1;
    }
    return wynik;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> tab[i];
    rozmiar = 1 << (__lg(2 * n) + 1);
    cout << bin_search() << "\n";
    return 0;
}