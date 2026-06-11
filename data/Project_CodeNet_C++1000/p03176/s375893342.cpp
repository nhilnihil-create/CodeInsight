#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Fleur{
    int poids;
    int valeur;
};

int32_t main()
{
    int nbFleur;
    cin >> nbFleur;

    Fleur fleur[nbFleur];

    int nbFeuille = 1 << ((int)ceil(log2(nbFleur+1)));

    int arbre[nbFeuille*2] = {0};

    for(int iFleur = 0; iFleur < nbFleur; iFleur++) {
        cin >> fleur[iFleur].poids;
    }

    for(int iFleur = 0; iFleur < nbFleur; iFleur++) {
        cin >> fleur[iFleur].valeur;
        int total = 0;
        int debut = nbFeuille, fin = fleur[iFleur].poids+nbFeuille-1;

        while(debut <= fin) {
            if(debut%2==1) {
                total = max(total, arbre[debut]);
                debut++;
            }
            if(fin%2==0) {
                total = max(total, arbre[fin]);
                fin--;
            }
            debut /= 2;
            fin /= 2;
        }

        arbre[fleur[iFleur].poids + nbFeuille] = max(arbre[fleur[iFleur].poids + nbFeuille], total + fleur[iFleur].valeur);

        int id = fleur[iFleur].poids + nbFeuille;
        while(id != 1) {
            id /= 2;
            arbre[id] = max(arbre[id*2], arbre[id*2+1]);
        }

    }

    cout << arbre[1];

    return 0;
}
