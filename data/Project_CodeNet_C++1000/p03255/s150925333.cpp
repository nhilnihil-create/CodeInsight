#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-result"
using namespace std;
typedef long long llg;

const llg borneMax = 2 * (llg)(1e5) + 5;
llg nbDechets, coutFixe;
llg pos[borneMax];
llg somme[borneMax];

int main()
{
    scanf("%lld%lld", &nbDechets, &coutFixe);
    for (llg indDechet = 1; indDechet <= nbDechets; ++indDechet) {
        scanf("%lld", &pos[indDechet]);
        somme[indDechet] = somme[indDechet - 1] + pos[indDechet];
    }
    llg reponse = LLONG_MAX;
    for (llg portesParTour = 1; portesParTour <= nbDechets; ++portesParTour) {
        llg dernier = nbDechets;
        llg sous = 0;
        for (llg indTour = 1; dernier > 0; ++indTour) {
            llg coefficient = max(5LL, 2*indTour+1);
            llg inv = somme[dernier];
            dernier -= portesParTour;
            dernier = max(dernier, 0LL);
            inv -= somme[dernier];
            llg ajout = coefficient*inv;
            if (ajout >= (LLONG_MAX - sous)) { sous = -1; break; }
            sous += ajout;
        }
        if (sous == -1) continue;
        sous += portesParTour*coutFixe;
        sous += nbDechets*coutFixe;
        reponse = min(reponse, sous);
    }
    printf("%lld\n", reponse);
}